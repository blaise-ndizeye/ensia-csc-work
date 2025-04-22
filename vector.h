#pragma once

class Vector {
  int *data, size, lastIndex = 0;

public:
  Vector(int size);
  void sumVect(const Vector &);
  void prodVect(const Vector &);
  virtual int getSize() const final;
  virtual void setSize(const int &) final;
  virtual void setAll(const int size, const int *newData);
  virtual const int *getData() const final;
  virtual void add(const int &);
  virtual void print() const final;
  virtual ~Vector() { delete[] data; };
};

class BitVector : public Vector {
  void validateBitNumber(const int &) const;

public:
  BitVector(int size);
  virtual void setAll(const int size, const int *newData) override;
  void sumVect(const BitVector &);
  void prodVect(const BitVector &);
  virtual void add(const int &) override;
  virtual ~BitVector() = default;
};