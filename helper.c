#include "helper.h"
#include <stdio.h>

void printvt(vtptr)
  struct vector_table *vtptr;
{
  printf("   D0 |    0     1     2     3 \n");
  printf("  ----|------------------------\n");
  printf("     0|  %3d   %3d   %3d   %3d\n",vtptr->costs[0][0],
	 vtptr->costs[0][1],vtptr->costs[0][2],vtptr->costs[0][3]);
  printf("     1|  %3d   %3d   %3d   %3d\n",vtptr->costs[1][0],
	 vtptr->costs[1][1],vtptr->costs[1][2],vtptr->costs[1][3]);
  printf("     2|  %3d   %3d   %3d   %3d\n",vtptr->costs[2][0],
	 vtptr->costs[2][1],vtptr->costs[2][2],vtptr->costs[2][3]);
  printf("     3|  %3d   %3d   %3d   %3d\n",vtptr->costs[3][0],
	 vtptr->costs[3][1],vtptr->costs[3][2],vtptr->costs[3][3]);

  printf("NEXT HOPS\n");
  for (unsigned int i = 0; i < 4; i++) {
    printf("%d ", vtptr->next_hops[i]);
  }
}

void copy_vector(int* v1, const int* v2, unsigned int length) {
  for (unsigned int i = 0; i < length; i++) {
    v1[i] = v2[i];
  }
}

int compare_vectors(const int* v1, const int* v2, unsigned int length) {
  for (unsigned int i = 0; i < length; i++) {
    if (v1[i] != v2[i]) {
      return 0;
    }
  }
  return 1;
}

void print_vector(const int* vector) {
  for (unsigned int i = 0; i < 4; i++) {
    printf("%d ", vector[i]);
  }
}

// void send_rtpkt(unsigned int source_id, const struct vector_table vt) {
//   struct rtpkt pkt;
//   pkt.sourceid = source_id;
//   copy_vector(pkt.mincost, vt.costs[source_id], 4);
// }