class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map = defaultdict(list)
        for word in strs:
            c1 = [0]*26
            for i in word:
                n = ord(i) - ord('a')
                c1[n] += 1

     
            map[tuple(c1)].append(word)
        

        return list(map.values())