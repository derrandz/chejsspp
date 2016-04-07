/*
 | ============
 | +  SquareView
 | +
 | ============
 */
#include "views/SquareView.hpp"
 
/**
 * The white suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const SquareView::whiteSuitPath = {"res/board/square/white_suit.jpg"};
#else
std::string const SquareView::whiteSuitPath = {"../res/board/square/white_suit.jpg"};
#endif // EMSCRIPTEN

/**
 * The black suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const SquareView::blackSuitPath = {"res/board/square/black_suit.jpg"};
#else
std::string const SquareView::blackSuitPath = {"../res/board/square/black_suit.jpg"};
#endif // EMSCRIPTEN

/*
 | ============
 | +  PawnView
 | +
 | ============
 */
#include "views/PawnView.hpp"
/**
 * The white suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const PawnView::whiteSuitPath = {"res/board/pieces/white/wP_80.png"};
#else
std::string const PawnView::whiteSuitPath = {"../res/board/pieces/white/wP_80.png"};
#endif // EMSCRIPTEN

/**
 * The black suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const PawnView::blackSuitPath = {"res/board/pieces/black/bP_80.png"};
#else
std::string const PawnView::blackSuitPath = {"../res/board/pieces/black/bP_80.png"};
#endif // EMSCRIPTEN

/*
 | ============
 | +  KingView
 | +
 | ============
 */
#include "views/KingView.hpp"
/**
 * The white suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const KingView::whiteSuitPath = {"res/board/pieces/white/wK_80.png"};
#else
std::string const KingView::whiteSuitPath = {"../res/board/pieces/white/wK_80.png"};
#endif // EMSCRIPTEN

/**
 * The black suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const KingView::blackSuitPath = {"res/board/pieces/black/bK_80.png"};
#else
std::string const KingView::blackSuitPath = {"../res/board/pieces/black/bK_80.png"};
#endif // EMSCRIPTEN

/*
 | ============
 | +  QueenView
 | +
 | ============
 */
#include "views/QueenView.hpp"
/**
 * The white suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const QueenView::whiteSuitPath = {"res/board/pieces/white/wQ_80.png"};
#else
std::string const QueenView::whiteSuitPath = {"../res/board/pieces/white/wQ_80.png"};
#endif // EMSCRIPTEN

/**
 * The black suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const QueenView::blackSuitPath = {"res/board/pieces/black/bQ_80.png"};
#else
std::string const QueenView::blackSuitPath = {"../res/board/pieces/black/bQ_80.png"};
#endif // EMSCRIPTEN

/*
 | ============
 | +  BishopView
 | +
 | ============
 */
#include "views/BishopView.hpp"
/**
 * The white suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const BishopView::whiteSuitPath = {"res/board/pieces/white/wB_80.png"};
#else
std::string const BishopView::whiteSuitPath = {"../res/board/pieces/white/wB_80.png"};
#endif // EMSCRIPTEN

/**
 * The black suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const BishopView::blackSuitPath = {"res/board/pieces/black/bB_80.png"};
#else
std::string const BishopView::blackSuitPath = {"../res/board/pieces/black/bB_80.png"};
#endif // EMSCRIPTEN

/*
 | ============
 | +  KnightView
 | +
 | ============
 */
#include "views/KnightView.hpp"
/**
 * The white suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const KnightView::whiteSuitPath = {"res/board/pieces/white/wN_80.png"};
#else
std::string const KnightView::whiteSuitPath = {"../res/board/pieces/white/wN_80.png"};
#endif // EMSCRIPTEN

/**
 * The black suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const KnightView::blackSuitPath = {"res/board/pieces/black/bN_80.png"};
#else
std::string const KnightView::blackSuitPath = {"../res/board/pieces/black/bN_80.png"};
#endif // EMSCRIPTEN

/*
 | ============
 | +  RookView
 | +
 | ============
 */
#include "views/RookView.hpp"
/**
 * The white suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const RookView::whiteSuitPath = {"res/board/pieces/white/wR_80.png"};
#else
std::string const RookView::whiteSuitPath = {"../res/board/pieces/white/wR_80.png"};
#endif // EMSCRIPTEN

/**
 * The black suit's path.
 * 
 */
#ifdef EMSCRIPTEN
std::string const RookView::blackSuitPath = {"res/board/pieces/black/bR_80.png"};
#else
std::string const RookView::blackSuitPath = {"../res/board/pieces/black/bR_80.png"};
#endif // EMSCRIPTEN