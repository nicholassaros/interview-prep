class Solution {
    class Element {
        int value;
        int freq;

        public Element(int freq, int value){
            this.value = value;
            this.freq = freq;
        }
    }

    public int[] topKFrequent(int[] nums, int k) {

        List<Integer> result = new ArrayList<>();
        Map<Integer,Integer> numsMap = new HashMap<>();
        PriorityQueue<Element> pq = new PriorityQueue<>((e1, e2) -> e2.freq - e1.freq);

        for(int num : nums){
            numsMap.merge(num,1,Integer::sum);
        }

        for(Map.Entry<Integer, Integer> entry : numsMap.entrySet()){
            // add to heap
            pq.add(new Element(entry.getValue(), entry.getKey()));
        }

        for(int i = 0; i < k; i++){
            if (!pq.isEmpty()) {
                Element element = pq.poll();
                result.add(element.value);
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();


        
    }
}
