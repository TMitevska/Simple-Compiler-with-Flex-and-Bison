#ifndef   _LIST_H
#define   _LIST_H


struct list_head
{
	struct list_head *next, *prev;
};

#define INIT_LIST_HEAD(ptr) do { \
        (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while(0)

#define list_empty(ptr)	((ptr)->next ==(ptr))? 1:0
#define list_entry(ptr, type, member) \
        ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member))) 


static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add_tail(struct list_head *add, struct list_head *head)
{
    __list_add(add, head->prev, head);
}

#define list_for_each(pos, head)  for (pos = (head)->next; pos != (head); pos = pos->next) 

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

static inline void __list_del(struct list_head * prev, struct list_head * next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);	
}

       
#endif
