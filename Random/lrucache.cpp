#include<iostream>
#include<unordered_map>

class LRUCache {
private:
    int _cap;
    struct cache{
        int _key, _value;
        cache *prev, *next;
        cache(int key, int value){
            prev = next = nullptr;
            _key = key;
            _value = value;
        }
    };
    cache *_head = new cache(-1, -1);
    cache *_tail = new cache(-1, -1);
    std::unordered_map<int, cache*> _m;
public:
    LRUCache(int capacity){
        _cap = capacity;
        _head->next = _tail;
        _tail->prev = _head;
    }
    
    int get(int key){
        if(_m.find(key) == _m.end()) return -1;
        _m[key]->prev->next = _m[key]->next;
        _m[key]->next->prev = _m[key]->prev;

        _m[key]->next = _head->next;
        _head->next = _m[key];
        _m[key]->prev = _head;
        _m[key]->next->prev = _m[key];
        return _m[key]->_value;
    }
    
    void put(int key, int value){
        if(_m.find(key) != _m.end()){
            _m[key]->_value = value;

            _m[key]->prev->next = _m[key]->next;
            _m[key]->next->prev = _m[key]->prev;

            _m[key]->next = _head->next;
            _head->next = _m[key];
            _m[key]->prev = _head;
            _m[key]->next->prev = _m[key];
        }
        else{
            if(_m.size() < _cap){
                cache *temp = new cache(-1, -1);
                temp->_key = key;
                temp->_value = value;
                _m[key] = temp;

                _m[key]->next = _head->next;
                _head->next = _m[key];
                _m[key]->prev = _head;
                _m[key]->next->prev = _m[key];
            }
            else{
                cache *temp = new cache(-1, -1);
                temp->_key = key;
                temp->_value = value;
                _m[key] = temp;

                _m.erase(_tail->prev->_key);
                _tail->prev->prev->next = _tail;
                _tail->prev = _tail->prev->prev;

                _m[key]->next = _head->next;
                _head->next = _m[key];
                _m[key]->prev = _head;
                _m[key]->next->prev = _m[key];
            }
        }
    }
};