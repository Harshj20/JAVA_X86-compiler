

class test_2 {
	public static void main(String[] args)
	{
		
		// //allocating memory for 5 integers.
		int []b = new int[5];

		//initialize the first elements of the array
		b[0] = 10;
		System.println(b[0]);

		// initialize the second elements of the array
		//arr[1] = 20;

		// so on...
		// arr[3] = 40;
		// arr[4] = 50;
		// arr[2] = 45;

        int arr[][]
            = { { 5, 5, 5 }, { 5, 5, 5 }, { 5, 5, 5 } };
		arr[0][2] = 30;
		System.println(arr[0][2]);
        int a[][][]={{{ 2, 7, 9 }, { 3, 6, 1 }, { 7, 4, 2 } },
                        {{ 2, 7, 9 }, { 3, 6, 1 }, { 7, 4, 2 } },
                        {{ 2, 7, 9 }, { 3, 6, 1 }, { 7, 4, 2 } }};
		System.println(a[0][1][2]);
		System.println(a[1][1][1]);


        arr[0][1]+=30;
		System.println(arr[0][1]);
	}
}
