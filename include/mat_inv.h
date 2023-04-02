/**
 * ESP-IDF component for performing matrix inversions
 *
 * code modified from : https://www.sanfoundry.com/c-program-find-inverse-matrix/
 **/

 void transpose3x3(float num[3][3], float fac[3][3], float r);

 void cofactor3x3(float num[3][3], float f);

 void determinant3x3(float a[3][3]);

 void inv_mat_3x3(float a[3][3], float dest[3][3]);

