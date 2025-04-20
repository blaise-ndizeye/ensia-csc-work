#pragma once

class Vector {
  int *data, size, lastIndex = 0;

public:
  Vector(int size);
  virtual void sumVect(const Vector &);
  virtual void prodVect(const Vector &);
  virtual int getSize() const final;
  virtual void setSize(const int &) final;
  virtual void setAll(const int size, const int *newData);
  virtual const int *getData() const final;
  virtual void add(const int &);
  virtual void print() const final;
  virtual ~Vector();
};

class BitVector : public Vector {
  void validateBitNumber(const int &) const;

public:
  BitVector(int size);
  virtual void setAll(const int size, const int *newData) override;
  virtual void sumVect(const Vector &) override;
  virtual void prodVect(const Vector &) override;
  virtual void add(const int &) override;
  virtual ~BitVector() = default;
};