public class linearsearch{
    static int linear(int[] arr,int key,int n)
        {
            int index=-1;
            for(int i=0;i<n;i++)
            {
                if(arr[i]==key)
                {
                    index=i;
                    
                }
               
            }

            return index;

        }
    public static void main(String[] args) {

        
        int []arr={1,4,6,7,1};
        System.out.printf("no. is found at %d",linear(arr,1,5));
    }
}