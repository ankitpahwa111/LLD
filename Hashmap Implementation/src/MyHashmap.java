public class MyHashmap<K,V> {

    Entry[] hashTable;
    final Integer INITIAL_CAPACITY = 1 >> 4;
    final Integer MAXIMUM_CAPACITY = 1 >> 30;

    MyHashmap() {
        hashTable = new Entry[INITIAL_CAPACITY];
    }

    MyHashmap(int capacity) {
        hashTable = new Entry[nextPower_2(capacity)];
//        System.out.println(hashTable.length);
    }

    int getNextPowerOfTwo(int capacity) {
        int n = capacity - 1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
    }

    int  nextPower_2 (int  x )
    {
        int  value  =  1 ;
        while  ( value  <=  x)
        {
            value  =  value  <<  1 ;
        }
        return  value ;
    }

    class Entry<K,V> {
        K key;
        V value;
        Entry next;

        Entry(K k, V v) {
            key = k;
            value = v;
            next = null;
        }
        public K getKey() {
            return key;
        }

        public void setKey(K key) {
            this.key = key;
        }

        public V getValue() {
            return value;
        }

        public void setValue(V value) {
            this.value = value;
        }

        public Entry getNext() {
            return next;
        }

        public void setNext(Entry next) {
            this.next = next;
        }
    }

    public void put (K key, V value) {
        int hashCode = key.hashCode() % hashTable.length;
        Entry node = hashTable[hashCode];
        if ( node == null) {
            hashTable[hashCode] = new Entry(key, value);
            return;
        }
        while(node.getNext()!=null) {
            if(node.getNext()==key) {
                node.setValue(value);
                return;
            }
            node = node.getNext();
        }
        Entry newNode = new Entry(key, value);
        node.setNext(newNode);
    }

    public V get(K key) {
        int hashCode = key.hashCode() % hashTable.length;
        Entry node = hashTable[hashCode];
        while(node!=null) {
            if(node.getKey().equals(key)) {
                return (V) node.getValue();
            }
            node = node.getNext();
        }
        return null;
    }

    public static void main(String[] args) {
        MyHashmap<Integer, String> map = new MyHashmap<>(7);
//        System.out.println(map.);
        map.put(1, "hi");
        map.put(2, "my");
        map.put(3, "name");
        map.put(4, "is");
        map.put(5, "Shrayansh");
        map.put(6, "how");
        map.put(7, "are");
        map.put(8, "you");
        map.put(9, "friends");
        map.put(10, "?");

        String value = map.get(0);
        System.out.println(value);
    }
}