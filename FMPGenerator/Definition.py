import itertools

class Signature:
    def __init__(self, name, args, ret, pr, cpr, upward, downward):
        self.mName = name
        self.mArgs = args
        self.mResult = ret
        self.mProcess = pr
        self.mCProcess = cpr
        self.mUpward = upward
        self.mDownward = downward
    def GetSignature(self):
        return self.mName + "".join(self.mArgs)
    def GetArgs(self):
        return self.mArgs
    def GetResult(self):
        return self.mResult
    def GetProcess(self):
        return self.mProcess
    def GetCProcess(self):
        return self.mCProcess
    def HasBuffer(self):
        return isinstance(self.mCProcess, int) == False
    def GetUpward(self):
        return self.mUpward
    def GetDownward(self):
        return self.mDownward

class Function1:
    def __init__(self, name, token = 0):
        self.mName = name
        self.mToken = token if token != 0 else name
        self.mSignatures = []
    def GetName(self):
        return self.mName
    def GetToken(self):
        return self.mToken
    def AddImpl(self, args, res, pr, cpr = 0, upward = True, downward = True):
        self.mSignatures.append(Signature(self.mName, args, res, pr, cpr, upward, downward))
    def GetSignatures(self):
        return self.mSignatures
    def SetIndex(self, i):
        self.mIndex = i
    def GetIndex(self):
        return self.mIndex
class Function2:
    def __init__(self, name, token = 0):
        self.mName = name
        self.mToken = token if token != 0 else name
        self.mSignatures = []
    def GetName(self):
        return self.mName
    def GetToken(self):
        return self.mToken
    def AddImpl(self, args, res, pr, cpr = 0, upward = True, downward = True):
        self.mSignatures.append(Signature(self.mName, args, res, pr, cpr, upward, downward))
    def GetSignatures(self):
        return self.mSignatures
    def SetIndex(self, i):
        self.mIndex = i
    def GetIndex(self):
        return self.mIndex
class Function3:
    def __init__(self, name, token = 0):
        self.mName = name
        self.mToken = token if token != 0 else name
        self.mSignatures = []
    def GetName(self):
        return self.mName
    def GetToken(self):
        return self.mToken
    def AddImpl(self, args, res, pr, cpr = 0, upward = True, downward = True):
        self.mSignatures.append(Signature(self.mName, args, res, pr, cpr, upward, downward))
    def GetSignatures(self):
        return self.mSignatures
    def SetIndex(self, i):
        self.mIndex = i
    def GetIndex(self):
        return self.mIndex

def GetFuncList():
    
    func1 = []
    func2 = []
    func3 = []
    oper1 = []
    oper2 = []
    oper3 = []
    index2 = []
    index3 = []
    
    #oper1.append(Function1("add"))
    #oper1[-1].AddImpl([ "Int" ], "Int", "return +a;")
    #oper1[-1].AddImpl([ "Flt" ], "Flt", "return +a;")

    oper1.append(Function1("sub"))
    oper1[-1].AddImpl([ "Int" ], "Int", "return -a;")
    oper1[-1].AddImpl([ "Flt" ], "Flt", "return -a;")
    oper1[-1].AddImpl([ "Vec" ], "Vec", "*mBuffer = a; *mBuffer *= -1; return *mBuffer;", "return a *= -1;", upward = False, downward = False)
    oper1[-1].AddImpl([ "Mat" ], "Mat", "*mBuffer = a; *mBuffer *= -1; return *mBuffer;", "return a *= -1;", upward = False, downward = False)
    
    oper2.append(Function2("pow"))
    #第2引数がintの場合、powは十分に速いのでdownwardを許可する。
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return fast_pow(a, b)")
    oper2[-1].AddImpl([ "Int", "Flt" ], "Flt", "return std::pow(a, b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Int" ], "Flt", "return fast_pow(a, b)")
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return std::pow(a, b)", upward = False, downward = False)

    oper2.append(Function2("mul"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return a * b")
    oper2[-1].AddImpl([ "Int", "Flt" ], "Flt", "return a * b")
    oper2[-1].AddImpl([ "Flt", "Int" ], "Flt", "return a * b")
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return a * b")
    oper2[-1].AddImpl([ "Vec", "Flt" ], "Vec", "*mBuffer = a; *mBuffer *= b; return *mBuffer", "return a * b", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Vec" ], "Vec", "*mBuffer = b; *mBuffer *= a; return *mBuffer", "return a * b", upward = False, downward = False)
    oper2[-1].AddImpl([ "Mat", "Flt" ], "Mat", "*mBuffer = a; *mBuffer *= b; return *mBuffer", "return a * b", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Mat" ], "Mat", "*mBuffer = b; *mBuffer *= a; return *mBuffer", "return a * b", upward = False, downward = False)
    oper2[-1].AddImpl([ "Mat", "Mat" ], "Mat", "*mBuffer = a * b; return *mBuffer", "return a * b", upward = False, downward = False)
    oper2[-1].AddImpl([ "Mat", "Vec" ], "Vec", "*mBuffer = a * b; return *mBuffer", "return a * b", upward = False, downward = False)

    oper2.append(Function2("div"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return a / b")
    oper2[-1].AddImpl([ "Int", "Flt" ], "Flt", "return a / b")
    oper2[-1].AddImpl([ "Flt", "Int" ], "Flt", "return a / b")
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return a / b")
    oper2[-1].AddImpl([ "Vec", "Flt" ], "Vec", "*mBuffer = a; *mBuffer /= b; return *mBuffer", "return a / b", upward = False, downward = False)

    oper2.append(Function2("mod"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return a % b")

    oper2.append(Function2("add"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return a + b")
    oper2[-1].AddImpl([ "Int", "Flt" ], "Flt", "return a + b")
    oper2[-1].AddImpl([ "Flt", "Int" ], "Flt", "return a + b")
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return a + b")
    oper2[-1].AddImpl([ "Str", "Str" ], "Str", "*mBuffer = a; *mBuffer += b; return *mBuffer", "return a + b", upward = False, downward = False)
    oper2[-1].AddImpl([ "Vec", "Vec" ], "Vec", "*mBuffer = a; *mBuffer += b; return *mBuffer", "return a + b", upward = False, downward = False)
    oper2[-1].AddImpl([ "Mat", "Mat" ], "Mat", "*mBuffer = a; *mBuffer += b; return *mBuffer", "return a + b", upward = False, downward = False)

    oper2.append(Function2("sub"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return a - b")
    oper2[-1].AddImpl([ "Int", "Flt" ], "Flt", "return a - b")
    oper2[-1].AddImpl([ "Flt", "Int" ], "Flt", "return a - b")
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return a - b")
    oper2[-1].AddImpl([ "Vec", "Vec" ], "Vec", "*mBuffer = a; *mBuffer -= b; return *mBuffer", "return a - b", upward = False, downward = False)
    oper2[-1].AddImpl([ "Mat", "Mat" ], "Mat", "*mBuffer = a; *mBuffer -= b; return *mBuffer", "return a - b", upward = False, downward = False)

    oper2.append(Function2("gt"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return (int64_t)(a > b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Int", "Flt" ], "Int", "return (int64_t)(a > b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Int" ], "Int", "return (int64_t)(a > b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Int", "return (int64_t)(a > b)", upward = False, downward = False)

    oper2.append(Function2("geq"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return (int64_t)(a >= b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Int", "Flt" ], "Int", "return (int64_t)(a >= b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Int" ], "Int", "return (int64_t)(a >= b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Int", "return (int64_t)(a >= b)", upward = False, downward = False)

    oper2.append(Function2("lt"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return (int64_t)(a < b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Int", "Flt" ], "Int", "return (int64_t)(a < b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Int" ], "Int", "return (int64_t)(a < b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Int", "return (int64_t)(a < b)", upward = False, downward = False)

    oper2.append(Function2("leq"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return (int64_t)(a <= b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Int", "Flt" ], "Int", "return (int64_t)(a <= b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Int" ], "Int", "return (int64_t)(a <= b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Int", "return (int64_t)(a <= b)", upward = False, downward = False)

    oper2.append(Function2("eq"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return (int64_t)(a == b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Int", "return (int64_t)(a == b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Str", "Str" ], "Int", "return (int64_t)(a == b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Vec", "Vec" ], "Int", "return (int64_t)(a == b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Mat", "Mat" ], "Int", "return (int64_t)(a == b)", upward = False, downward = False)

    oper2.append(Function2("neq"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return (int64_t)(a != b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Int", "return (int64_t)(a != b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Str", "Str" ], "Int", "return (int64_t)(a != b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Vec", "Vec" ], "Int", "return (int64_t)(a != b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Mat", "Mat" ], "Int", "return (int64_t)(a != b)", upward = False, downward = False)

    oper2.append(Function2("and"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return (int64_t)(a && b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Int", "Flt" ], "Int", "return (int64_t)(a && b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Int" ], "Int", "return (int64_t)(a && b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Int", "return (int64_t)(a && b)", upward = False, downward = False)

    oper2.append(Function2("or"))
    oper2[-1].AddImpl([ "Int", "Int" ], "Int", "return (int64_t)(a || b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Int", "Flt" ], "Int", "return (int64_t)(a || b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Int" ], "Int", "return (int64_t)(a || b)", upward = False, downward = False)
    oper2[-1].AddImpl([ "Flt", "Flt" ], "Int", "return (int64_t)(a || b)", upward = False, downward = False)
    
    index2.append(Function2("index2"))
    index2[-1].AddImpl([ "Str", "Int" ], "Str", "*mBuffer = a[b]; return *mBuffer;", "return std::string(1, a[b]);")
    index2[-1].AddImpl([ "Vec", "Int" ], "Flt", "return a[b];")


    func1.append(Function1("sin"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::sin(a)")
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::sin(a)")

    func1.append(Function1("cos"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::cos(a)")
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::cos(a)")

    func1.append(Function1("tan"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::tan(a)")
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::tan(a)")
    
    func1.append(Function1("asin"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::asin(a)", upward = False, downward = False)
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::asin(a)", upward = False, downward = False)

    func1.append(Function1("acos"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::acos(a)", upward = False, downward = False)
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::acos(a)", upward = False, downward = False)
    
    func1.append(Function1("atan"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::atan(a)", upward = False, downward = False)
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::atan(a)", upward = False, downward = False)
    
    func1.append(Function1("ln"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::log(a)", upward = False, downward = False)
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::log(a)", upward = False, downward = False)
    
    func1.append(Function1("log10"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::log10(a)", upward = False, downward = False)
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::log10(a)", upward = False, downward = False)
    
    func1.append(Function1("exp"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::exp(a)", upward = False, downward = False)
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::exp(a)", upward = False, downward = False)
    
    func1.append(Function1("square"))
    func1[-1].AddImpl([ "Int" ], "Int", "return a * a")
    func1[-1].AddImpl([ "Flt" ], "Flt", "return a * a")
    
    func1.append(Function1("cube"))
    func1[-1].AddImpl([ "Int" ], "Int", "return a * a * a")
    func1[-1].AddImpl([ "Flt" ], "Flt", "return a * a * a")
    
    func1.append(Function1("sqrt"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::sqrt(a)", upward = False, downward = False)
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::sqrt(a)", upward = False, downward = False)
    
    func1.append(Function1("cbrt"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return std::cbrt(a)", upward = False, downward = False)
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::cbrt(a)", upward = False, downward = False)

    func1.append(Function1("ceil"))
    func1[-1].AddImpl([ "Int" ], "Int", "return (int64_t)std::ceil(a)")
    func1[-1].AddImpl([ "Flt" ], "Int", "return (int64_t)std::ceil(a)")

    func1.append(Function1("floor"))
    func1[-1].AddImpl([ "Int" ], "Int", "return (int64_t)std::floor(a)")
    func1[-1].AddImpl([ "Flt" ], "Int", "return (int64_t)std::floor(a)")
    
    func1.append(Function1("int"))
    func1[-1].AddImpl([ "Int" ], "Int", "return (int64_t)a")
    func1[-1].AddImpl([ "Flt" ], "Int", "return (int64_t)a")
    
    func1.append(Function1("float"))
    func1[-1].AddImpl([ "Int" ], "Flt", "return (double)a")
    func1[-1].AddImpl([ "Flt" ], "Flt", "return (double)a")
    
    func1.append(Function1("abs"))
    func1[-1].AddImpl([ "Int" ], "Int", "return a < 0 ? -a : a")
    func1[-1].AddImpl([ "Flt" ], "Flt", "return std::abs(a)")

    func1.append(Function1("len"))
    func1[-1].AddImpl([ "Str" ], "Int", "return a.size()", upward = False, downward = False)
    func1[-1].AddImpl([ "Vec" ], "Int", "return a.size()", upward = False, downward = False)
    
    func1.append(Function1("transpose"))
    func1[-1].AddImpl([ "Mat" ], "Mat", "*mBuffer = a.transpose(); return *mBuffer;", "return a.transpose();", upward = False, downward = False)
    func1.append(Function1("trace"))
    func1[-1].AddImpl([ "Mat" ], "Flt", "return a.trace();", upward = False, downward = False)

    func2.append(Function2("atan2"))
    func2[-1].AddImpl([ "Int", "Int" ], "Flt", "return std::atan2(a, b)", upward = False, downward = False)
    func2[-1].AddImpl([ "Int", "Flt" ], "Flt", "return std::atan2(a, b)", upward = False, downward = False)
    func2[-1].AddImpl([ "Flt", "Int" ], "Flt", "return std::atan2(a, b)", upward = False, downward = False)
    func2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return std::atan2(a, b)", upward = False, downward = False)

    func2.append(Function2("log2"))
    func2[-1].AddImpl([ "Int", "Int" ], "Flt", "return std::log2(a) / std::log2(b)", upward = False, downward = False)
    func2[-1].AddImpl([ "Int", "Flt" ], "Flt", "return std::log2(a) / std::log2(b)", upward = False, downward = False)
    func2[-1].AddImpl([ "Flt", "Int" ], "Flt", "return std::log2(a) / std::log2(b)", upward = False, downward = False)
    func2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return std::log2(a) / std::log2(b)", upward = False, downward = False)
    
    func2.append(Function2("max"))
    func2[-1].AddImpl([ "Int", "Int" ], "Int", "return std::max(a, b)", downward = False)
    func2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return std::max(a, b)", downward = False)

    func2.append(Function2("min"))
    func2[-1].AddImpl([ "Int", "Int" ], "Int", "return std::min(a, b)", downward = False)
    func2[-1].AddImpl([ "Flt", "Flt" ], "Flt", "return std::min(a, b)", downward = False)

    func2.append(Function2("vec2"))
    func2[-1].AddImpl([ "Flt", "Flt" ], "Vec",\
                      "mBuffer->resize(2); *mBuffer << a, b; return *mBuffer;",\
                      "Eigen::VectorXd v(2); v << a, b; return v;",\
                      downward = False)

    func2.append(Function2("mat2"))
    func2[-1].AddImpl([ "Vec", "Vec" ], "Mat",\
                      "mBuffer->resize(a.size(), 2); *mBuffer << a, b; return *mBuffer;",\
                      "Eigen::MatrixXd m(a.size(), 2); m << a, b; return m;",\
                      upward = False, downward = False)
    func2.append(Function2("diag2"))
    func2[-1].AddImpl([ "Flt", "Flt" ], "Mat",\
                      "*mBuffer = Eigen::MatrixXd::Zero(2, 2); mBuffer->diagonal() << a, b; return *mBuffer;",\
                      "Eigen::MatrixXd m = Eigen::MatrixXd::Zero(2, 2); m.diagonal() << a, b; return m;",\
                      upward = False, downward = False)

    func2.append(Function2("dot"))
    func2[-1].AddImpl([ "Vec", "Vec" ], "Flt", "return a.dot(b);", upward = False, downward = False)

    func2.append(Function2("cross"))
    func2[-1].AddImpl([ "Vec", "Vec" ], "Vec",\
                      "*mBuffer = a.head<3>().cross(b.head<3>()); return *mBuffer;",\
                      "return a.head<3>().cross(b.head<3>());",\
                      upward = False, downward = False)

    func3.append(Function3("if"))
    func3[-1].AddImpl([ "Int", "Int", "Int" ], "Int", "return a ? b : c", upward = False, downward = False)
    func3[-1].AddImpl([ "Int", "Flt", "Flt" ], "Flt", "return a ? b : c", upward = False, downward = False)
    func3[-1].AddImpl([ "Int", "Str", "Str" ], "Str", "return a ? b : c", upward = False, downward = False)
    func3[-1].AddImpl([ "Int", "Vec", "Vec" ], "Vec", "return a ? b : c", upward = False, downward = False)
    
    func3.append(Function3("vec3"))
    func3[-1].AddImpl([ "Flt", "Flt", "Flt" ], "Vec",\
                      "mBuffer->resize(3); *mBuffer << a, b, c; return *mBuffer;",\
                      "Eigen::VectorXd v(3); v << a, b, c; return v;",\
                      downward = False)

    func3.append(Function3("mat3"))
    func3[-1].AddImpl([ "Vec", "Vec", "Vec" ], "Mat",\
                      "mBuffer->resize(a.size(), 3); *mBuffer << a, b, c; return *mBuffer;",\
                      "Eigen::MatrixXd m(a.size(), 3); m << a, b, c; return m;",\
                      upward = False, downward = False)
    func3.append(Function2("diag3"))
    func3[-1].AddImpl([ "Flt", "Flt", "Flt" ], "Mat",\
                      "*mBuffer = Eigen::MatrixXd::Zero(3, 3); mBuffer->diagonal() << a, b, c; return *mBuffer;",\
                      "Eigen::MatrixXd m = Eigen::MatrixXd::Zero(3, 3); m.diagonal() << a, b, c; return m;",\
                      upward = False, downward = False)

    index3.append(Function3("index3"))
    index3[-1].AddImpl([ "Mat", "Int", "Int" ], "Flt", "return a(b, c);")

    for i, o in enumerate(itertools.chain(func1, func2, func3, oper1, oper2, oper3, index2, index3)):
        o.SetIndex(i)

    return (func1, func2, func3, oper1, oper2, oper3, index2, index3)

def GetModifiers():
    return [ "Terminal", "Juncture" ]
def GetNodes():
    return [ "Terminal", "Function" ]
def GetTypes():
    return [ "Int", "Flt", "Str", "Vec", "Mat" ]