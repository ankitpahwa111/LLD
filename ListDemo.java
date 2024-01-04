import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class ListDemo {
    // Functions provided on top of Collection interface -
    //  add(idx, val) , set(idx, val) , remove(idx) , indexOf(val) -> first occurrence, get(idx)
    // replaceAll(UnaryOperator) , sort(mandatory Comparator), forEach(lambda)
    // ListIterator

    public static void main(String[] args) {
        // ArrayList is one of the implementation of List interface
        // ArrayList -> is not threadSafe
        // -> maintains insertion order
        // -> Null elements are allowed
        // -> Duplicates are allowed
        List<Integer> list1 = new ArrayList<Integer>(10);
        list1.add(0,100);
        list1.add(1,200);
        list1.add(2,300);

        list1.add(1, 50); // will add new element and shift right

        System.out.println(list1); // since list is iterable, this will print elements

        list1.set(1,500);  // override the index
        System.out.println(list1);

        list1.remove(1);
        System.out.println(list1);
        System.out.println(list1.size());

        list1.sort((Integer a, Integer b) -> b-a);
        System.out.println(list1);

        list1.add(100);
        list1.add(100);
        System.out.println(list1);
        System.out.println(list1.indexOf(100)); // first index of 100

        list1.replaceAll((Integer a) -> -a);  // similar to map in JS
        System.out.println(list1);

        list1.forEach((Integer a) -> System.out.println(a));

        // LL implements both List and Deque interfaces, so it has addFirst(element) and add(idx,element) both
        // Not thread safe
        LinkedList<Integer> ll = new LinkedList<>();
        ll.add(1);
        ll.add(2);
        ll.addFirst(12);
        ll.add(2, 200);
        ll.set(2,500);
        System.out.println("LinkedList:" + ll);

        // Stack extends Vector and Stack is Thread Safe
        // Additional functions in stack - push, peek, pop
        Stack<Integer> stack = new Stack<>();
        stack.push(100);
        stack.add(1);
        stack.add(2);
        stack.add(3);
        while (!stack.isEmpty()) {
            System.out.println(stack.peek());
            stack.pop();
        }

    }
}
