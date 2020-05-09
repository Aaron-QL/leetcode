class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int left = 0, right = 0;
        int maxLen = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        for (; right < s.length(); right++) {
            if (map.containsKey(s.charAt(right))) {
                left = Math.max(map.get(s.charAt(right)), left);
            }
            maxLen = Math.max(right - left + 1, maxLen);
            map.put(s.charAt(right), right + 1);
        }
        return maxLen;
    }
}
