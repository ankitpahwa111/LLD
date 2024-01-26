public class Multithreading {

    public static void main(String[] args) {
        // Create two threads, one for odd numbers and another for even numbers
        Thread oddThread = new Thread(() -> printNumbers(true), "OddThread");
        Thread evenThread = new Thread(() -> printNumbers(false), "EvenThread");

        // Start both threads
        oddThread.start();
        evenThread.start();
    }

    private static void printNumbers(boolean isOdd) {
        for (int i = isOdd ? 1 : 2; i <= 10; i += 2) {
            System.out.println(Thread.currentThread().getName() + ": " + i);
            try {
                // Introduce a short delay to make the output more readable
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
