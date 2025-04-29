#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    // 맨 처음에는 A로만 이루어짐
    // name: 만들고자 하는 이름
    
    // 다음 알파벳 이동할 때 위 화살표
    int aCnt=0;
    for(int i=0;i<name.size();++i)
    {
        char c=name[i];
        if(c == 'A')
        {
           ++aCnt;
        }
        answer += min(c-'A', 'Z'-c+1);
        
        cout<<"here: "<<answer<<"\n";
    }
    
    cout<<answer<<"\n";
    
    int move = name.size()-1;
    answer = answer + move - aCnt;
    
    
    return answer;
}