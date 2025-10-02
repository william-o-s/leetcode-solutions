class Router {
private:
    using packet = tuple<int, int, int>;
public:
    Router(int memoryLimit)
    : limit_{static_cast<size_t>(memoryLimit)}
    , packets_{set<packet>{}}
    , order_{queue<packet>{}}
    , dsts_{unordered_map<int, deque<int>>{}} {}
    
    bool addPacket(int source, int destination, int timestamp) {
        // check for duplicate
        auto pack = packet{source, destination, timestamp};
        if (packets_.count(pack)) {
            return false;
        }

        // if packets >= memoryLimit, must forwardPacket()
        if (packets_.size() >= limit_) {
            forwardPacket();
        }

        packets_.insert(pack);
        order_.push(pack);

        if (not dsts_.count(destination)) {
            auto tss = deque<int>{};
            tss.push_back(timestamp);
            dsts_.emplace(destination, move(tss));
        } else {
            dsts_[destination].push_back(timestamp);
        }

        return true;
    }
    
    vector<int> forwardPacket() {
        // return empty vec if no packets
        if (order_.empty()) {
            return vector<int>{};
        }

        // remove from order_
        auto result = order_.front();
        order_.pop();

        // remove from packets_
        packets_.erase(result);

        // remove from dsts_
        auto [src, dst, ts] = result;
        auto& tss = dsts_[dst];
        tss.pop_front();
        if (tss.empty()) {
            dsts_.erase(dst);
        }

        return vector<int>{src, dst, ts};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (not dsts_.count(destination)) {
            return 0;
        }

        auto& tss = dsts_[destination];
        auto lo = lower_bound(tss.begin(), tss.end(), startTime);
        auto hi = upper_bound(tss.begin(), tss.end(), endTime);
        return static_cast<int>(hi - lo);
    }
private:
    size_t limit_;
    // set<(int, int, int)> // lookup by (src, dst, ts)
    set<packet> packets_;
    // queue<(int, int, int)> // fifo order of packets
    queue<packet> order_;
    // unordered_map<(int, deque<int>)> // lookup dst -> packet times. inserted and deleted in fifo order, supports random access iterator and thus if inserted in sorted timestamp order binary search
    unordered_map<int, deque<int>> dsts_;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
