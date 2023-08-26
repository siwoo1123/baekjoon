#include <iostream>
#include <cstring>
using namespace std;

char str[200005], alpha;
int alphabats[30][200005], n, a, b, len;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> str;
    len = strlen(str);
    
    alphabats[str[0]-'a'][0] = 1;
    
    for(int i = 1; i < len; i++) {
        alphabats[0][i] = alphabats[0][i-1];
        alphabats[1][i] = alphabats[1][i-1];
        alphabats[2][i] = alphabats[2][i-1];
        alphabats[3][i] = alphabats[3][i-1];
        alphabats[4][i] = alphabats[4][i-1];
        alphabats[5][i] = alphabats[5][i-1];
        alphabats[6][i] = alphabats[6][i-1];
        alphabats[7][i] = alphabats[7][i-1];
        alphabats[8][i] = alphabats[8][i-1];
        alphabats[9][i] = alphabats[9][i-1];
        alphabats[10][i] = alphabats[10][i-1];
        alphabats[11][i] = alphabats[11][i-1];
        alphabats[12][i] = alphabats[12][i-1];
        alphabats[13][i] = alphabats[13][i-1];
        alphabats[14][i] = alphabats[14][i-1];
        alphabats[15][i] = alphabats[15][i-1];
        alphabats[16][i] = alphabats[16][i-1];
        alphabats[17][i] = alphabats[17][i-1];
        alphabats[18][i] = alphabats[18][i-1];
        alphabats[19][i] = alphabats[19][i-1];
        alphabats[20][i] = alphabats[20][i-1];
        alphabats[21][i] = alphabats[21][i-1];
        alphabats[22][i] = alphabats[22][i-1];
        alphabats[23][i] = alphabats[23][i-1];
        alphabats[24][i] = alphabats[24][i-1];
        alphabats[25][i] = alphabats[25][i-1];
        alphabats[str[i]-'a'][i]++;
    }
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> alpha >> a >> b;
        if(a==0) cout << alphabats[alpha-'a'][b] << '\n';
        else cout << alphabats[alpha-'a'][b] - alphabats[alpha-'a'][a - 1] << '\n';
    }
    
    return 0;
}
