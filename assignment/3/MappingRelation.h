// Hongyi Lin 300053082
// Stacy Guo 300157080

#ifndef CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_
#define CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_

template<typename Domain, typename Range>
class MappingRelation;

template<typename Domain, typename Range>
class MappingRelation {
 public:
  MappingRelation() = default;
  MappingRelation(const MappingRelation<Domain, Range>& other);
  ~MappingRelation() = default;

 private:
};

#endif // CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_
