

public class HelloWorld {
    public static void main(String[] args) {
        long a = 0;
        int data_length = 1024;
        long data[] = new long[data_length];
        long n = 1024*720*3*100;
        System.out.println("loop count is " + n);
        long time = System.currentTimeMillis();
        for(long i = 0; i < n; i++){
            a += 1;
            data[(int)i%data_length] += a;
        }
        long pad = System.currentTimeMillis() - time;
        System.out.println("java cost " + pad + " ms");
    }
}