- アルゴリズムの方針
  - 案1
    - 上から見て降順にソートされた小さいスタックを作る

- クイックソートなるものを実装したい
  - pivot

- 要素数で分類
  - 1
    - 何もしない
case 1
a | 1
b |

  - 2
    - 大小関係によりswap
case 1
a | 1 2
b |
sa
a | 2 1
b |

a | 2 1
b |


  - 3
    - bにpushして要素が2の問題に帰着させる?
case 1
a | 1 2 3
b |
ra
a | 3 1 2
b |
sa
a | 3 2 1
b |

case 2
a | 1 3 2
b |
rra
a | 3 2 1
b |

case 2
a | 2 1 3
b |
ra
a | 3 2 1
b |

case 3
a | 2 3 1
b |
pb
a | 2 3
b | 1
sa
a | 3 2
b | 1
pa
a | 3 2 1
b |

case 4
a | 3 2 1
b |

case 5
a | 3 1 2
b |
sa
a | 3 2 1
b |

  - 4
    - aのトップの値をpivotにして、bに降順にスタック

case 1
a | 1 2 3 4
b |

case 2
a | 1 3 2 4
b |
sa pb
a | 1 3 4
b | 2
sa pb
a | 1 4
b | 2 3
pb pb
a | 1 4 3 2
b |
rra
a | 4 3 2 1
b |

case 3
a | 1 2 4 3
b |
sa ra
a | 4 1 2 3
b |
sa pb
a | 4 1 3
b | 2
sa pb
a | 4 3
b | 2 1
sb
a | 4 3
b | 1 2
pa pa
a | 4 3 2 1
b |

- 分割数を増やす
6 5 4 3 2 1 0
3 2 1 0

a | 4 3 0 2 1 6 5
b |

pivot : 3
半分に分ける
a | 4 6 5
b | 1 2 0 3

さらに半分に
a | 4 6 5
b | 1 2 0 3