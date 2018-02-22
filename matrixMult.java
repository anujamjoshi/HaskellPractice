 public class matrixMult {

   private static long start_time = 0;
   private static long end_time = 0;
   private static double totalTime = 0;

   public static void main(String[] args) {

      //Matrix1
      double[][] arr1 = new double[][]{
        { 1.0, 2.0, 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0, 9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 },
        { 21.0, 22.0, 23.0, 24.0, 25.0 }
      };

      //Matrix2
      double[][] arr2 = new double[][]{
        { 1.0, 2.0, 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0, 9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 },
        { 21.0, 22.0, 23.0, 24.0, 25.0 }
      };

      //Matrix Multiplication
      double[][] arr3 = mult(arr1, arr2);
      System.out.println("---MATRIX MULT RESULT---\n" + toString(arr3));

      //Run-time Analysis
      for (int i=0; i < 10; i++){
         start_time = System.nanoTime();
         double[][] result = mult(arr1, arr2);
         end_time = System.nanoTime();

         totalTime += (end_time - start_time);
      }

      double avgTime = totalTime/10.0;
      System.out.println("Java Matrix Mult Average time taken: " + avgTime + " nanoseconds.");
   }

   /**
   * This is the matrix multiplication method on nxn matrices.
   * @param double a[][], double b[][] Two matrices.
   * @return The product of the two matrices.
   */
   public static double[][] mult(double a[][], double b[][]){
      if(a.length == 0) {
         return new double[0][0];
      }
      if(a[0].length != b.length) {
         return null; //invalid dims
      }
    
      int n = a[0].length;
    
      double result[][] = new double[n][n];
    
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
               result[i][j] += a[i][k] * b[k][j];
            }
         }
      }
      return result;
   }


   /**
   * This method turns the matrix into a printable value
   * @param double a[][] A matrix.
   * @return String 
   */
   public static String toString(double a[][]) {
      String matrix = "";

      int n = a[0].length;

      for (int row=0; row < n; row++) {
         String matrixRow = "";
         for (int col=0; col < n; col++) {
            matrixRow += String.valueOf(a[row][col]) + " ";
         }
         matrix += matrixRow + "\n";
      }
      return matrix;
   }

 }
