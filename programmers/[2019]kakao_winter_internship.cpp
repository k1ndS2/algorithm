
// 크레인 인형뽑기 게임
// https://programmers.co.kr/learn/courses/30/lessons/64061

#include <string>
#include <vector> 

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int now = 0;
    vector<int> bucket;
    for(int i = 0 ; i < moves.size(); i++){
        now = moves[i]-1;
        for(int r = 0 ; r < board.size(); r++){
            if(board[r][now]) {
                // bucket에 담기
                bucket.push_back(board[r][now]);
                // board 변경
                board[r][now] = 0;
                
                // 이전과 같은지
                int bucketSz = bucket.size();
                if(bucketSz > 1 && bucket[bucketSz-2] == bucket[bucketSz-1]){                    
                    bucket.pop_back();
                    bucket.pop_back();
                    answer = answer + 2;
                }
                break;
            }
        }
        
    }
    return answer;
}
