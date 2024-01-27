import java.net.StandardSocketOptions;
import java.util.concurrent.*;

public class ThreadPoolExecutorExample {

    // ThreadPoolExecutor creates a collection of Threads
    // When tasks are given to ThreadPoolExecutor , it assigns a thread from idle threads
    // If no threads are idle, the task is added to waiting queue.
    // If queue is also full and a new task comes into the executor, it will create threads up till maxThreads value to handle this task
    // If maxThreads are utilized and still a new task comes, we can define a rejectionPolicy or choose from existing ones

    public static void main(String[] args) {
        ThreadPoolExecutor threadPoolExecutor = new ThreadPoolExecutor(
                2,
                5,
                1,
                TimeUnit.MINUTES,
                new ArrayBlockingQueue<>(2),
                new CustomThreadCreator(),
                new CustomTaskRejectionPolicy()
        );
        for(int i=1; i<=8; i++) {
            int finalI = i;
            threadPoolExecutor.execute(()-> {
                System.out.println("Task number " + finalI + " picked by " + Thread.currentThread().getName());
                try{
                    Thread.sleep(2000);
                } catch (Exception e) {}
            });
        }
        threadPoolExecutor.shutdown(); // Shutdown means all execting threads will finish tasks and then kill
    }

}

class CustomThreadCreator implements ThreadFactory {

    @Override
    public Thread newThread(Runnable r) {
        return new Thread(r);
    }
}

class CustomTaskRejectionPolicy implements RejectedExecutionHandler{

    @Override
    public void rejectedExecution(Runnable r, ThreadPoolExecutor executor) {
        System.out.println("Rejected task " + r.toString());
    }
}
