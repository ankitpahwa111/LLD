import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        // functions exposed by PQ in java
        // add, offer - to add new element, returns true if success
        // remove, poll - to remove element and return it
        // peek , element - to peek the front or top element of Queue

        // Priority Queue implements Queue , so all these methods are present
        PriorityQueue<Integer> minPq = new PriorityQueue<>(); // By default it natural ordering - minHeap
        minPq.add(2);
        minPq.add(3);
        minPq.add(4);
        minPq.add(5);
        minPq.add(6);
        while(!minPq.isEmpty()) {
            System.out.println(minPq.poll());
        }

        System.out.println("--------------------------------------------------");

        // To make a maxHeap , we need to pass comparator in PQ constructor
        PriorityQueue<Integer> maxPq = new PriorityQueue<>((Integer a, Integer b) -> b-a);
        PriorityQueue<Integer> maxPq2 = new PriorityQueue<>(Collections.reverseOrder());  // Collections.reverseOrder() is util function provided by Collections class
        PriorityQueue<String> maxPq3 = new PriorityQueue<>((String a, String b) -> b.compareTo(a));
        maxPq.add(2);
        maxPq.add(3);
        maxPq.add(4);
        maxPq.add(5);
        maxPq.add(6);
        maxPq2.addAll(maxPq);  // Adds copy of all element of one Collection to other ( does not remove from first collection )
        while(!maxPq.isEmpty()) {
            System.out.println(maxPq.poll());
        }

        System.out.println("----------------------------------------");
        while(!maxPq2.isEmpty()) {
            System.out.println(maxPq2.poll());
        }

    }
}