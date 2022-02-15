// Optimize this function

void singleThread(int N, int *matA, int *matB, int *output)
{
    
    int N4 = N<<2, N5 = N>>1; 
	
    // enforce N to be power of 2 and greater than 2
    assert(N>=4 and N == ( N &~ (N-1)));
    for(int colSetB = 0; colSetB < N; colSetB += 4){
    
        for(int rowA = 0; rowA < N; rowA+=16){
        
            int sum[32] = {0};
            for(int indexE = rowA*N, indexE2 = indexE + (N<<1), indexE3 = indexE + N4, indexE4 = indexE2 + N4, indexE5 = indexE3 + N4, indexE6 = indexE4 + N4, indexE7 = indexE5 + N4, indexE8 = indexE6 + N4, indexO = indexE + N, indexO2 = indexO + (N<<1), indexO3 = indexO + N4, indexO4 = indexO2 + N4 , indexO5 = indexO3 + N4, indexO6 = indexO4 + N4 ,indexO7 = indexO5 + N4, indexO8 = indexO6 + N4, indexB = colSetB+1+N; indexE < (rowA+1)*N; ) {
           
                        int col = matB[indexB];   
                        int col2 = matB[indexB+2];
                        
                        int col3 = matB[indexB - N - 1];
                        int col4 = matB[indexB - N + 1];
                        
                        int col5 = matB[indexB - 1];
                        int col6 = matB[indexB + 1];
                        
                        int col7 = matB[indexB - N];
                        int col8 = matB[indexB - N + 2];
                        indexB += (N<<1);
                        
                        int col9 = matB[indexB];   
                        int col10 = matB[indexB+2];
                        
                        int col11 = matB[indexB - N - 1];
                        int col12 = matB[indexB - N + 1];
                        
                        int col13 = matB[indexB - 1];
                        int col14 = matB[indexB + 1];
                        
                        int col15 = matB[indexB - N];
                        int col16 = matB[indexB - N + 2];
                        indexB += (N<<1);
                        
                        sum[0] += matA[indexE] * col + matA[indexE+1] * col3 + matA[indexE+2] * col9 + matA[indexE+3] * col11;
                        
                        sum[1] += matA[indexE] * col2 + matA[indexE+1] * col4 + matA[indexE+2] * col10 + matA[indexE+3] * col12;
                        indexE+=4;
                        
                        sum[2] += matA[indexO] * col5 + matA[indexO+1] * col7 + matA[indexO+2] * col13 + matA[indexO+3] * col15;
                        
                        sum[3] += matA[indexO] * col6 + matA[indexO+1] * col8 + matA[indexO+2] * col14 + matA[indexO+3] * col16;
                        indexO += 4;
                        
                        sum[4] += matA[indexE2] * col + matA[indexE2+1] * col3 + matA[indexE2+2] * col9 + matA[indexE2+3] * col11;
                        
                        sum[5] += matA[indexE2] * col2 + matA[indexE2+1] * col4 + matA[indexE2+2] * col10 + matA[indexE2+3] * col12;
                        indexE2+=4;
                        
                        sum[6] += matA[indexO2] * col5 + matA[indexO2+1] * col7 + matA[indexO2+2] * col13 + matA[indexO2+3] * col15;
                        
                        sum[7] += matA[indexO2] * col6 + matA[indexO2+1] * col8 + matA[indexO2 +2 ] * col14 + matA[indexO2+3] * col16;
                        indexO2+=4;
                        
                        sum[8] += matA[indexE3] * col + matA[indexE3+1] * col3 + matA[indexE3+2] * col9 + matA[indexE3+3] * col11;
                        
                        sum[9] += matA[indexE3] * col2 + matA[indexE3+1] * col4 + matA[indexE3+2] * col10 + matA[indexE3+3] * col12;
                        indexE3+=4;
                        
                        sum[10] += matA[indexO3] * col5 + matA[indexO3+1] * col7 + matA[indexO3+2] * col13 + matA[indexO3+3] * col15;
                        
                        sum[11] += matA[indexO3] * col6 + matA[indexO3+1] * col8 + matA[indexO3+2] * col14 + matA[indexO3+3] * col16;
                        indexO3+=4;
                        
                        sum[12] += matA[indexE4] * col + matA[indexE4+1] * col3 + matA[indexE4+2] * col9 + matA[indexE4+3] * col11;
                        
                        sum[13] += matA[indexE4] * col2 + matA[indexE4+1] * col4 + matA[indexE4+2] * col10 + matA[indexE4+3] * col12;
                        indexE4+=4;
                        
                        sum[14] += matA[indexO4] * col5 +  matA[indexO4+1] * col7 + matA[indexO4+2] * col13 +  matA[indexO4+3] * col15;
                        
                        sum[15] += matA[indexO4] * col6 + matA[indexO4+1] * col8 + matA[indexO4+2] * col14 + matA[indexO4+3] * col16;
                        indexO4+=4;
                        
                        
                        sum[16] += matA[indexE5] * col + matA[indexE5+1] * col3 + matA[indexE5+2] * col9 + matA[indexE5+3] * col11;
                        
                        sum[17] += matA[indexE5] * col2 + matA[indexE5+1] * col4 + matA[indexE5+2] * col10 + matA[indexE5+3] * col12;
                        indexE5+=4;
                        
                        sum[18] += matA[indexO5] * col5 + matA[indexO5+1] * col7 + matA[indexO5+2] * col13 + matA[indexO5+3] * col15;
                        
                        sum[19] += matA[indexO5] * col6 + matA[indexO5+1] * col8 + matA[indexO5+ 2] * col14 + matA[indexO5+3] * col16;
                        indexO5+=4;
                        
                        sum[20] += matA[indexE6] * col + matA[indexE6+1] * col3 + matA[indexE6+2] * col9 + matA[indexE6+3] * col11;
                        
                        sum[21] += matA[indexE6] * col2 + matA[indexE6+1] * col4 + matA[indexE6+2] * col10 + matA[indexE6+3] * col12;
                        indexE6+=4;
                        
                        sum[22] += matA[indexO6] * col5 + matA[indexO6+1] * col7 + matA[indexO6+2] * col13 + matA[indexO6+3] * col15;
                        
                        sum[23] += matA[indexO6] * col6 + matA[indexO6+1] * col8 + matA[indexO6+2] * col14 + matA[indexO6+3] * col16;
                        indexO6+=4;
                        
                        sum[24] += matA[indexE7] * col + matA[indexE7+1] * col3 + matA[indexE7+2] * col9 + matA[indexE7+3] * col11;
                        
                        sum[25] += matA[indexE7] * col2 + matA[indexE7+1] * col4 + matA[indexE7+2] * col10 + matA[indexE7+3] * col12;
                        indexE7+=4;
                        
                        sum[26] += matA[indexO7] * col5 + matA[indexO7+1] * col7 + matA[indexO7+2] * col13 + matA[indexO7+3] * col15;
                        
                        sum[27] += matA[indexO7] * col6 + matA[indexO7+1] * col8 + matA[indexO7+2] * col14 + matA[indexO7+3] * col16;
                        indexO7+=4;
                        
                        sum[28] += matA[indexE8] * col + matA[indexE8+1] * col3 + matA[indexE8+2] * col9 + matA[indexE8+3] * col11;
                        
                        sum[29] += matA[indexE8] * col2 + matA[indexE8+1] * col4 + matA[indexE8+2] * col10 + matA[indexE8+3] * col12;      
                        indexE8+=4;   
                                       
                        sum[30] += matA[indexO8] * col5 + matA[indexO8+1] * col7 + matA[indexO8+2] * col13 + matA[indexO8+3] * col15;
                        
                        sum[31] += matA[indexO8] * col6 + matA[indexO8+1] * col8 + matA[indexO8+2] * col14 + matA[indexO8+3] * col16;    
                        indexO8+=4;  
             
                        
                }
            
            // compute output indices
            int indexC = (rowA>>1) * N + (colSetB>>1);
            
            output[indexC] = sum[0];
            output[indexC + 1] = sum[1];
            output[indexC + N5] = sum[2];
            output[indexC + N5+ 1] = sum[3];
            
            indexC += N;
            output[indexC] = sum[4];
            output[indexC + 1] = sum[5];
            output[indexC + N5] = sum[6];
            output[indexC + N5 + 1] = sum[7];
            
            indexC += N;
            output[indexC] = sum[8];
            output[indexC + 1] = sum[9];
            output[indexC + N5] = sum[10];
            output[indexC + N5 + 1] = sum[11];
            
            indexC += N;
            output[indexC] = sum[12];
            output[indexC + 1] = sum[13];
            output[indexC + N5] = sum[14];
            output[indexC + N5 + 1] = sum[15];
            
            indexC += N;
            output[indexC] = sum[16];
            output[indexC + 1] = sum[17];
            output[indexC + N5] = sum[18];
            output[indexC + N5 + 1] = sum[19];
            
            indexC += N;
            output[indexC] = sum[20];
            output[indexC + 1] = sum[21];
            output[indexC + N5] = sum[22];
            output[indexC + N5 + 1] = sum[23];
            
            indexC += N;
            output[indexC] = sum[24];
            output[indexC + 1] = sum[25];
            output[indexC + N5] = sum[26];
            output[indexC + N5 + 1] = sum[27];
            
            indexC += N;
            output[indexC] = sum[28];
            output[indexC + 1] = sum[29];
            output[indexC + N5] = sum[30];
            output[indexC + N5 + 1] = sum[31];
            
        }
    }
}

