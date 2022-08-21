class Illustrate
{
  private:
    int x;
    static int y;       // private static member
  public:
    static int count;   // public static variable

    void print() const;           // METHODS
    void setX (int a);
    static void incrementY();     // static function
    Illustrate(int a=0);          // default parameter
                                  // if no value is passed for a, set a=0
};
