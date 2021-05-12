all: quicksort.c mergesort.c heapsort.c
  gcc quicksort.c -o quicksort
  gcc heapsort.c -o heapsort
  gcc mergesort.c -o mergesort
clean:
  rm heapsort
  rm mergesort
  rm quicksort
