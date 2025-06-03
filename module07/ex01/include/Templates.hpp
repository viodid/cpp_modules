#ifndef TEMPLATE_H
#define TEMPLATE_H

template <typename TArr, typename TFpt>
void iter(TArr arr, int len, TFpt fpt)
{
    for (int i = 0; i < len; i++) {
        arr[i] = fpt(arr[i]);
    }
}

#endif
