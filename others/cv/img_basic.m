function [ output_args ] = img_basic(filename)
    im=imread('0.jpg');
    
    fr=im(:,:,1);   %Rͨ������
    fg=im(:,:,2);
    fb=im(:,:,3);
    
    subplot(221); imshow(fr); title('R') ; %subplot(mnp), m-by-n matrix
    subplot(222); imshow(fg); title('G') ; 
    %subplot(223); imshow(fb); title('B') ; 
     
    subplot(223); 
    
    %�Ҷ�����
    %subplot(224); imcontour(fb,1); title('�Ҷ�����') ; imshow(im)   
    
    %��Ե���
    %edge(fg, 'canny', 0.3); title('edge') ;imshow(im) %0.3Ϊ��ֵ(0~1)
    
    %�Ҷȵ���
    %im = imadjust(fr);
    %im = imadjust(fr, [0.5 0.6], [0.4 0.6]);imshow(im)
    
    %ֱ��ͼ����
    %[im, T] = histeq(fr);imshow(im); subplot(224); imhist(im,4); %imhistĬ�ϲ�����256
    
    %ɫ����ǿ
    %im = decorrstrech(im);imshow(im)
    
    %�˲�
    %im = rgb2gray(im); im = medfilt2(im);imshow(im)
    
    %ͼ��ʴ,����ͻ�������ĺڵ��
    %se = strel('disk', 11);im = imerode(im, se); imshow(im)
    %ͼ������
    %se = strel('disk', 11);im = imdilate(im, se); imshow(im)    
    
    %��������˹��ͼ��
    %lapmask = [1 1 1; 1 -8 1; 1 1 1 ]; se = strel('disk', 5);im = imerode(im, se);
    %im = im - imfilter(im, lapmask, 'replicate'); imshow(im)
    
    %ͼ���ݶ�
    [VG, A, PPG] = colorgrad(im);imshow(VG)  %colorgrad���������еĹ��������
    
end

