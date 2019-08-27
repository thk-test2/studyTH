
rgb_list = []

def rgb(N, R, G, B):
    if len(rgb_list) == 0:
        if R < G and R < B:
            return rgb_list.append( ('R', R) )
        elif G < R and G < B:
            return rgb_list.append( ('G', G) )
        elif B < R and B < G:
            return rgb_list.append( ('B', B) )

    if N < len(rgb_list):
        return rgb_list[N]
    
    if rgb_list[N-1][0] == 'R':
        if G < B:
            new_rgb = ('G', G)
        else:
            new_rgb = ('B', B)
    elif rgb_list[N-1][0] == 'G':
        if R < B:
            new_rgb = ('R', R)
        else:
            new_rgb = ('B', B)
    else :
        if R < G:
            new_rgb = ('R', R)
        else:
            new_rgb = ('G', G)
    # print(new_rgb)
    prev_rgb = rgb(N-1, R, G, B)
    # print(prev_rgb)
    rgb_list.append( (new_rgb[0], prev_rgb[1]+new_rgb[1]) )
    return rgb_list[N]

N = int(input())

for i in range(N):
    R,G,B = map(int, input().split())
    rgb(i, R, G, B)

print(rgb_list[N-1][1])
# print(rgb_list)