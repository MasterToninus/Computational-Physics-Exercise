class Lock{

  int *mutex;
public:
  Lock( void ){
    int state = 0;
    cudaMalloc( (void **)&mutex, sizeof(int) );
    cudaMemcpy( mutex, &state, sizeof(int), cudaMemcpyHostToDevice);
  }

  ~Lock( void ){
    cudaFree(mutex);
  }

  __device__ void lock( void ){
    while( atomicCAS( mutex, 0, 1 ) != 0 );
  }


  __device__ void unlock( void ){
    atomicExch( mutex, 0);
  }

  __host__ void reInit( void ){//Metodo in caso di doppia chiamata del distruttore
    //int state = 0;
    cudaMalloc( (void **)&mutex, sizeof(int) );
    //cudaMemcpy( mutex, &state, sizeof(int), cudaMemcpyHostToDevice);
  }

};
