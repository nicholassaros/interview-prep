class Solution {
    public boolean isAnagram(String s, String t) {

        if (s.length() != t.length()){
            return false;
        }

        List<Character> s_list = new ArrayList<>();
        List<Character> t_list = new ArrayList<>();

        for(int i = 0; i < s.length(); i++){
            s_list.add(s.charAt(i));
            t_list.add(t.charAt(i));
        }

        Collections.sort(t_list);
        Collections.sort(s_list);


        for(int i = 0; i<s_list.size(); i++){
            if (s_list.get(i) != t_list.get(i)){
                return false;
            }
        }





        return true;
    }
}
