__global__ void CMM(int* matA, int* matB, int* output, int N)
{
	int i = threadIdx.x + (blockIdx.x << 8);
	int rowA = i / (N>>1);
	int colSetB = (i % (N>>1)) << 1;
	int sum = 0;   
                
        for(int indexA = rowA*N, indexB = colSetB+(!(rowA&1))+N, indexB2 = colSetB+(rowA&1); indexA < (rowA+1)*N; 
                        indexA += 2, indexB += (N<<1), indexB2 += (N<<1)) {
             sum += matA[indexA] * matB[indexB];
             sum += matA[indexA+1] * matB[indexB2];
                
        }
            
            
        int indexC = (rowA>>1) * N + ((colSetB>>1) + (N>>1) * (rowA&1));
        output[indexC] = sum;
        
}

// Fill in this function
void gpuThread(int N, int *matA, int *matB, int *output)
{
	int *A, *B, *C;
	
	int size = sizeof(int)*(N*(N>>1));
	int se = sizeof(int)*(N*N);
	
	cudaMalloc(&A, se);
	cudaMalloc(&B, se);
	cudaMalloc(&C, size);
	
	cudaMemcpy(A, matA, se, cudaMemcpyHostToDevice);
	cudaMemcpy(B, matB, se, cudaMemcpyHostToDevice);
	

	CMM<<< 32, 256>>>(A, B, C, N);  
	
	cudaMemcpy(output, C, size, cudaMemcpyDeviceToHost);
	
	cudaFree(A);
	cudaFree(B);
	cudaFree(C);
	
}


