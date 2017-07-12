def mergeSort(alist):
    print("Splitting ",alist)
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)

        print("--- Start of process ---")
        i=0
        j=0
        k=0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1
        print("  [Sort & Merge]: ",alist[:k])
        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1
            print("  [Merge_left_L]: ",alist)
        while j < len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
            print("  [Merge_left_R]: ",alist)
        print("--- End of process ---")
    print("Merging ",alist)

alist = [54,26,93,17,77,31,44,55,20]
mergeSort(alist)
print(alist)
