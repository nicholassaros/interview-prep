class Solution {
    public String longestCommonPrefix(String[] strs) {
        // Loop over element to find char index

        String result = "";

        for(int i = 0; i<strs[0].length(); i++){
            char currentChar = strs[0].charAt(i);

            for(String word : strs){
                if (i >= word.length()){
                    return result;
                }

                char wordChar = word.charAt(i);
                if (currentChar != wordChar){
                    return result;
                }
            }

            System.out.println(currentChar);
            result+=currentChar;
        }


        return result;
    }
}