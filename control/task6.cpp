
#include <cstdlib>
#include <cassert>
#include <iostream>

struct JumpList { JumpList *next, *jump; void *data; unsigned min_distance; };

void restore_min_distance(JumpList *head)
{
    if (head->jump)
    {
        if (head->jump->min_distance == 0)
            head->jump->min_distance = head->min_distance + 1;
        else
            head->jump->min_distance = std::min(head->min_distance + 1, head->jump->min_distance);
        restore_min_distance(head->jump);
    } 
    else if (head->next) 
    {
        if (head->next->min_distance == 0)
            head->next->min_distance = head->min_distance + 1;
        else
            head->next->min_distance = std::min(head->min_distance + 1, head->next->min_distance);
        restore_min_distance(head->next);
    }
    else
    {
        return;
    }
}

int main() 
{
    JumpList *elements = new JumpList[6];
    elements[0] = JumpList{.next = &elements[1], .jump = &elements[3], .data = nullptr, .min_distance = 0u};
    elements[1] = JumpList{.next = &elements[2], .jump = &elements[4], .data = nullptr, .min_distance = 0u};
    elements[2] = JumpList{.next = &elements[3], .jump = &elements[5], .data = nullptr, .min_distance = 0u};
    elements[3] = JumpList{.next = &elements[4], .jump = &elements[5], .data = nullptr, .min_distance = 0u};
    elements[4] = JumpList{.next = &elements[5], .jump = nullptr, .data = nullptr, .min_distance = 0u};
    elements[5] = JumpList{.next = nullptr, .jump = nullptr, .data = nullptr, .min_distance = 0u};

    restore_min_distance(elements);

    for (int i = 0; i < 6; i++)
    {
        std::cout << elements[i].min_distance << " ";
    }

    assert(
        0 == elements[0].min_distance and
        1 == elements[1].min_distance and
        2 == elements[2].min_distance and
        1 == elements[3].min_distance and
        2 == elements[4].min_distance and
        2 == elements[5].min_distance 
    );
    delete[] elements;
	return 0;
}