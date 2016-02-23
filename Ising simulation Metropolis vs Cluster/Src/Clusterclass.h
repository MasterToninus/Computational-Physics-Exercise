//\*
//		Classe Cluster, contiene la lista degli elementi del cluster ed è possibile unire due claster con la classe somma
//*\

class cluster{
public:
	int N_ele; 						//Nelementi del cluster
	vector<int> i;vector<int> j;	//vector delle coo (i ,j) degli elementi del cluster
	int label;						//labello del cluster
	
cluster(int label_in, int i_in, int j_in, int N) //N= numero di nodi nel reticolo
	{
		N_ele=1;
		label= label_in;	 
		i.reserve(N); j.reserve(N);
		i.push_back(i_in);j.push_back(j_in);  
	}

~cluster(){ //http://www.unrealproject.org/forum/index.php?topic=1501.0
	//cout<<"Destructor called! label "<< label<<endl;
}

cluster& operator+=(cluster A){
	for(int k=0;k<A.N_ele;k++){
		i.push_back(A.i[k]);j.push_back(A.j[k]); //aggiungo gli elementi del cluster A alla lista degli elementi inziali
	}
	N_ele+=A.N_ele; //
	}

	void stampa(){ //funzioni che restituiscono la componente gli elementi del cluster
		for(int k=0;k<N_ele;k++){
			cout<<i[k]<<"\t"<<j[k]<<endl;
		}
	}
};

