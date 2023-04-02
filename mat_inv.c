float determinant3x3(float a[3][3])
{
    //ESP_LOGI(TAG, "finding det");
  float s = 1, det = 0, b[3][3];
  int i, j, m, n, c;
  int k = 3;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
    //ESP_LOGI(TAG, "det found!");
	return (det);
}

void cofactor3x3(float num[3][3], float dest[3][3])
{
 float b[3][3], fac[3][3];
 int p, q, m, n, i, j;
 int f = 3;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = a[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, dest, fac);
}

/*Finding transpose of matrix*/ 
void transpose3x3(float num[3][3], float dest[3][3], float fac[3][3])
{
  int i, j;
  int r = 3;
  //float b[3][3], inverse[3][3], d;
  float b[3][3], dest[3][3], d;
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
	}
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        dest[i][j] = b[i][j] / d;
        }
    }
   //ESP_LOGI(TAG,"\n\n\nThe inverse of matrix is : \n");
   /*for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         //ESP_LOGI(TAG,"\t%f", inverse[i][j]);
        }
    //ESP_LOGI(TAG,"\n");
     }
	 */
}

/* a->input matrix, dest->output inverted matrix, k->kxk dimensionality*/
void inv_mat3x3(float a[3][3], float dest[3][3]){
    float d = determinant(a,dest);
    if(d == 0){ESP_LOGI(TAG, "\nInverse of entered matrix is not possible\n");}
    else{cofactor(a,dest);}
}
