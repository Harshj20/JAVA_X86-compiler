public class Add {
    int x;
    char y;
    public int add(int a, int b){
        return a+b;
    }
    Add(int a, int b){
        this.x = a + b;
    }
}

class test_14{
    public static void main(String[] args){
        Add a = new Add(10, 20);
        // a.x = 1;
        int x = a.x + 1;
        System.println(x);
    }
}
