func sortArrayByParityII(A []int) []int {
    for i, j := 0, 1; i < len(A) && j < len(A); {
        for i < len(A) && A[i] % 2 == 0 {
            i += 2
        }
        for (j < len(A) && A[j] % 2 == 1) {
            j += 2;
        }
        if i < len(A) && j < len(A) {
            swap(&A[i], &A[j])
        }
    }
    return A
}

func swap(a, b *int) {
    t := *a
    *a = *b
    *b = t
}