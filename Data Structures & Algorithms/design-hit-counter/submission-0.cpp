class HitCounter {
private:
    std::deque<int> hitDeque;
public:
    HitCounter(){}
    
    void hit(int timestamp) {
        hitDeque.push_front(timestamp);
    }
    
    int getHits(int timestamp) {
        int hitCounter = 0;
        for (auto it = hitDeque.begin(); it != hitDeque.end(); it++) {
            if (*it > timestamp - 300) {
                hitCounter++;
            }
        }

        return hitCounter;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
