class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp;
        int n = matrix.size();

        bool first = true;
        int i = 0;
        int j = 0;
        int l = 0;
        while(true){
            if(j < n-2+l && !first){
                j++;
            }
            else if(!first){
                l++;
                j = l;
                i = l;
                
                n-=2;
            }
            if(n <= 1){
                break;
            }
            first = false;

            temp = matrix[i][j];
            for(int h = 0;h < 4;h++){
                cout << i << "-" << j << endl;
                cout << "-----------------------" << endl;
                swap(temp,matrix[j][matrix.size()-i-1]);
                int a = j;
                j = matrix.size()-i-1;
                i = a;
                for(int a = 0; a < matrix.size() ; a++){
                    for(int b = 0; b < matrix.size(); b++){
                        cout << matrix[a][b] << "--" ;
                    }
                    cout << endl;
                    cout << "------------------------------------------------" << endl;
                }
            }  

        }

        /*
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                temp = matrix[i][j];
                swap(temp, matrix[j][matrix.size()-i-1]);
                //swap(matrix[i][j],matrix[matrix.size()-j-1][i]);
            }
        }
        */
    }
};