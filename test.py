import itertools


def get_all_permutations(input_string):
    # Tách chuỗi thành các ký tự riêng lẻ
    characters = list(input_string)
    # Tạo tất cả các hoán vị
    permutations = set(itertools.permutations(characters))
    # Chuyển đổi các hoán vị từ tuple về chuỗi
    permutations_list = [''.join(p) for p in permutations]
    return permutations_list


# Chuỗi đầu vào
input_str = "stauiliss"
# Nhận tất cả các hoán vị
all_permutations = get_all_permutations(input_str)
# Trả về số lượng và 10 hoán vị đầu tiên để kiểm tra
len(all_permutations), all_permutations[:10]
