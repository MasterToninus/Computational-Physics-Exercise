__global__ void matrixMultiplyShared(float * A, float * B, float * C,
                                    int numARows, int numAColumns,
                                    int numBRows, int numBColumns,
                                    int numCRows, int numCColumns) 
{
    __shared__ float sA[32][32];   // Tile size of 32x32 
    __shared__ float sB[32][32];

    int Row = blockDim.y*blockIdx.y + threadIdx.y;
    int Col = blockDim.x*blockIdx.x + threadIdx.x;
    float Cvalue = 0.0;
    sA[threadIdx.y][threadIdx.x] = 0.0;
    sB[threadIdx.y][threadIdx.x] = 0.0;

    for (int k = 0; k < (((numAColumns - 1)/ 32) + 1); k++)
    {
        if ( (Row < numARows) && (threadIdx.x + (k*32)) < numAColumns)
        {
            sA[threadIdx.y][threadIdx.x] = A[(Row*numAColumns) + threadIdx.x + (k*32)];
        }
        else
        {
            sA[threadIdx.y][threadIdx.x] = 0.0;
        }            
        if ( Col < numBColumns && (threadIdx.y + k*32) < numBRows)
        {
            sB[threadIdx.y][threadIdx.x] = B[(threadIdx.y + k*32)*numBColumns + Col];
        }
        else
        {
            sB[threadIdx.y][threadIdx.x] = 0.0;
        }            
        __syncthreads();

        for (int j = 0; j < 32; ++j)
        {
            Cvalue += sA[threadIdx.y][j] * sB[j][threadIdx.x];
        }
    }
    if (Row < numCRows && Col < numCColumns)
    {
        C[Row*numCColumns + Col] = Cvalue;
    }
}

