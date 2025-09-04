    void pop() {
        if (!isEmpty()) {
            --top;
        }
    }
};

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {3, 1, 2};
    int n = 3;
    int grr[3];
    int crr[3];

    
    for (int i = 0; i < n; i++) {
        grr[i] = arr[i];
    }

    
    sort(grr, n);

    stack s;
    int idx = 0; 

    for (int i = 0; i < n; i++) {
        s.push(arr[i]);

       
        while (!s.isEmpty() && s.topElement() == grr[idx]) {
            crr[idx] = s.topElement();
            s.pop();
            idx++;
        }
    }

    
    for (int i = 0; i < n; i++) {
        cout << crr[i] << " ";
    }

    return 0;
}
