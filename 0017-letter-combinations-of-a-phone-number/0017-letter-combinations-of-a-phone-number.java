class Solution {
    List<String> res; StringBuilder comb; HashMap<Character,String> map;
    public List<String> letterCombinations(String digits) {
        res = new ArrayList<>(); if(digits.isEmpty()) return res;
        comb = new StringBuilder(); fillMap();
        dfs(0,digits);
        return res;
    }
    public void dfs(int i, String digits){
        if(i==digits.length()){
            res.add(comb.toString()); return;
        }
        String currString = map.get(digits.charAt(i));
        for(char c: currString.toCharArray()){
            comb.append(c);
            dfs(i+1,digits);
            comb.deleteCharAt(comb.length()-1);
        }
    }
    public void fillMap(){
        map = new HashMap(); map.put('2',"abc"); map.put('3',"def"); 
        map.put('4',"ghi"); map.put('5',"jkl"); map.put('6',"mno");
        map.put('7',"pqrs"); map.put('8',"tuv"); map.put('9',"wxyz"); 
    }
}