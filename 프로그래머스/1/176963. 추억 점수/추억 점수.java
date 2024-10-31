class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];  // photo 길이만큼 배열 초기화
        
        for(int i = 0; i < photo.length; i++) {
            int sum = 0;  // 각 사진별 점수 합계
            for(int j = 0; j < photo[i].length; j++) {  // 각 사진의 인물 순회
                for(int k = 0; k < name.length; k++) {  // name 배열과 비교
                    if(name[k].equals(photo[i][j])) {  // 문자열 비교는 equals 사용
                        sum += yearning[k];  // 해당하는 그리움 점수 추가
                        break;
                    }
                }
            }
            answer[i] = sum;  // 각 사진의 총점을 배열에 저장
        }
        
        return answer;
    }
}