import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

public class Deque {
    public static void main(String[] args) {
        // Queue is an interface having following funcs -
        // add(), offer(), poll() , remove(), peek(), element()
        // LL implements these functions, and is used to implement Queue as well
        // Deque and PriorityQueue also implement them
        // But Deque is again an interface , and it's implemented by ArrayDeque

        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.add(4);
        while(!queue.isEmpty()) {
            System.out.println(queue.poll());
        }

        // Deque interfaces addiionally provides these fucntions
        // addFirst() ,offerFirst(),  removeFirst() , pollFirst() , peekFirst(), getFirst()
        // addLast() , offerLast() , removeLast() , pollLast() , peekLast(), getLast()
        // If we use parent's methods , it will act as generic Queue ( addLast and getFirst )
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        deque.addFirst(1);
        System.out.println(deque.getFirst());
        deque.pollFirst();
        deque.pollFirst();

        // If we use addLast and pollFirst always , deque will act as Queue
        // If we use addLast and pollLast always, deque will act as Stack
    }
}
