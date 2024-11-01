class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];  // 문자열 길이만큼 배열 생성
        
        // 각 위치별로 가장 가까운 같은 글자 찾기
        for(int i = 0; i < s.length(); i++) {
            answer[i] = -1;  // 기본값 -1로 설정
            
            // 현재 위치(i)보다 앞에 있는 문자들을 뒤에서부터 검사
            for(int j = i - 1; j >= 0; j--) {
                if(s.charAt(i) == s.charAt(j)) {
                    answer[i] = i - j;  // 현재 위치와의 거리 계산
                    break;  // 가장 가까운 것을 찾았으므로 중단
                }
            }
        }
        
        return answer;
    }
}