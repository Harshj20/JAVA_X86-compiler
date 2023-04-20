//Java code for using 'this' keyword to
//refer current class instance variables
class test_10
{
	public static int main(int x)
	{   
        int z = 15;
        while(true){
            if(10 < 12){
                z= 67;
                int a = 10;
                break;
            }
            else{
                z = 7;
                int k = 10;
                continue;
            }
        }
        System.println(z);

        while(true){
            if(10 > 12){
                z= 67;
                int a = 10;
                continue;
            }
            else{
                z = 7;
                int k = 10;
                break;
            }
        }
        System.println(z);
        return 1;
	}
}
