public class Add {
    int x;
    char y;
    public void set(int a){
        this.x = a;
    }
    Add(int a, int b){
        this.x = a + b;
    }
    public int sum(int a, int b){
        return a+b;
    }
}

class test_12{
    public static void main(String[] args){

        Add a = new Add();
        a.set(10);
        // a.x = 1;
        int y = a.x + 1 + Add.sum(10, 20);
        System.println(y);
        
        int q[][] = new int[3][3];
        q[0][0] = 1;
        q[0][1] = 2;
        q[0][2] = 3;
        q[1][0] = 4;
        q[1][1] = 5;
        q[1][2] = 6;
        q[2][0] = 7;
        q[2][1] = 8;
        q[2][2] = 9;
        int sum = 0;
        for(int i = 0; i < 3; i++){
            int j = 0;
            while(j < 3){
                sum += q[i][j];
                j++;
            }
        }
        
        System.println(sum);
    }
}
