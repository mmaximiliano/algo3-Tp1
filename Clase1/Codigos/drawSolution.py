import chess
import chess.svg

board = chess.Board("Q7/4Q3/7Q/5Q2/2Q5/6Q1/1Q6/3Q4 w - - 0 1")
svg = chess.svg.board(board=board)
svg_file = open('./solution.svg','w')
svg_file.write(svg)
svg_file.close()
