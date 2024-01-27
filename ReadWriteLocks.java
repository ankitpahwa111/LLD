import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

class ReadWriteLockHelper{
    void produce(ReadWriteLock lock) {
        try{
            lock.readLock().lock();
            System.out.println("Read lock acquired by: "+ Thread.currentThread().getName());
            Thread.sleep(2000);
            System.out.println("Read lock released by: "+ Thread.currentThread().getName());
            lock.readLock().unlock();
        } catch (Exception e){}
    }
    void consume(ReadWriteLock lock) {
        try{
            lock.writeLock().lock();
            System.out.println("Write lock acquired by: "+ Thread.currentThread().getName());
            Thread.sleep(2000);
            System.out.println("Write lock released by: "+ Thread.currentThread().getName());
            lock.writeLock().unlock();
        } catch (Exception e){}
    }
}

public class ReadWriteLocks {
    //ReadWriteLock = SharedLock (Read Locks) can be acquired by anyone simultaneously
    // ExclusiveLock(Write Lock) is acquired only when there is no existing lock ,
    // and no read lock can happen if there is existing Exclusive lock

    public static void main(String[] args) {
        ReadWriteLock lock = new ReentrantReadWriteLock();
        ReadWriteLockHelper readWriteLockHelper = new ReadWriteLockHelper();
        new Thread(()->readWriteLockHelper.produce(lock), "Thread1").start();
        new Thread(()->readWriteLockHelper.produce(lock), "Thread2").start();
        new Thread(()->readWriteLockHelper.consume(lock), "Thread3").start();
    }
}
