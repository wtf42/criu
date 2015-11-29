#ifndef __CR_SEIZE_H__
#define __CR_SEIZE_H__

extern int collect_pstree(pid_t pid);
extern void pstree_switch_state(struct pstree_item *root_item, int st);

struct freezer_state {
	struct list_head list;

	char		*path;
	const char	*state;
};

extern struct list_head	freezer_states;

#endif
