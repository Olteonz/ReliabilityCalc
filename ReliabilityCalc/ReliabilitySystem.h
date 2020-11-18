#ifndef RELIABILITYSYSTEM_H
#define RELIABILITYSYSTEM_H
#include <vector>
class RealiabilityNode {
public:
	double reliability;
	RealiabilityNode* next;
	RealiabilityNode* branch;
};

#endif //
