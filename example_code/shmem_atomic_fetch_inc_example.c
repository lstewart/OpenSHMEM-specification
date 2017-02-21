#include <stdio.h>
#include <shmem.h>

int dst;

int main(void)
{
   int me;
   int old;

   shmem_init();
   me = shmem_my_pe();

   old = -1;
   dst = 22;
   shmem_barrier_all();

   if (me == 0)
      old = shmem_atomic_fetch_inc(&dst, 1);

   shmem_barrier_all();
   printf("%d: old = %d, dst = %d\n", me, old, dst);
   shmem_finalize();
   return 0;
}
